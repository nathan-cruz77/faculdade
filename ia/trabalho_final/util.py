import json
import random
import math
from collections import Counter

def nearest(a, lst, ndigits=5):
    distances = [round(abs(x - a), ndigits) for x in lst]

    if min(distances) == 0:
        return lst[distances.index(0)]

    if distances.count(0.1) > 1:
        aux = distances.index(0.1)
        return random.choice([lst[aux], lst[aux + 1]])

    return lst[distances.index(min(distances))]


def precision(number):
    try:
        ndigits = len(str(number).split('.')[1])
    except IndexError:
        ndigits = 1

    return ndigits


def custom_range(start, stop=None, step=1):
    ndigits = precision(step)

    if stop is None:
        stop, start = start, 0

    while(start < stop):
        yield round(start, ndigits)
        start += step


def is_number(num):
    try:
        float(num)
    except ValueError:
        return False
    return True


def is_continuous(x):
    return is_number(x)


def most_common(lista):
    return Counter(lista).most_common(1)[0][0]


def normalizer(data):
    frequencies = [i['frequency'] for i in data]
    impedance_real = [i['impedance_real'] for i in data]
    impedance_imag = [i['impedance_imaginary'] for i in data]

    maior_freq, menor_freq = max(frequencies), min(frequencies)
    maior_imped_real, menor_imped_real = max(impedance_real), min(impedance_real)
    maior_imped_imag, menor_imped_imag = max(impedance_imag), min(impedance_imag)

    for data_element in data:
        data_element['frequency'] -= menor_freq
        data_element['frequency'] /= (maior_freq - menor_freq)

        data_element['impedance_real'] -= menor_imped_real
        data_element['impedance_real'] /= (maior_imped_real - menor_imped_real)

        data_element['impedance_imaginary'] -= menor_imped_imag
        data_element['impedance_imaginary'] /= (maior_imped_imag - menor_imped_imag)


def log_normalizer(data):
    frequencies = [i['frequency'] for i in data]
    impedance_real = [i['impedance_real'] for i in data]
    impedance_imag = [i['impedance_imaginary'] for i in data]

    for data_element in data:
        data_element['frequency'] = math.log(abs(data_element['frequency']))
        data_element['impedance_real'] = math.log(abs(data_element['impedance_real']))
        data_element['impedance_imaginary'] = math.log(abs(data_element['impedance_imaginary']))


def load(data_file):
    with open(data_file) as data_f:
        data_set = json.load(data_f)

    log_normalizer(data_set)
    return data_set


def load_data_id3(filename):
    return load(filename)


def load_data_knn(filename):
    return load(filename)
