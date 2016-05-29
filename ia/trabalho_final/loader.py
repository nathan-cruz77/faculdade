import json

import numpy as np

def normalize(data):

    frequencies = [i[0][0] for i in data]
    impedance_real = [i[0][1] for i in data]
    impedance_imag = [i[0][2] for i in data]

    maior_freq, menor_freq = max(frequencies), min(frequencies)
    maior_imped_real, menor_imped_real = max(impedance_real), min(impedance_real)
    maior_imped_imag, menor_imped_imag = max(impedance_imag), min(impedance_imag)

    for data_element in data:

        data_element[0][0] -= menor_freq
        data_element[0][0] /= (maior_freq - menor_freq)

        data_element[0][1] -= menor_imped_real
        data_element[0][1] /= (maior_imped_real - menor_imped_real)

        data_element[0][2] -= menor_imped_imag
        data_element[0][2] /= (maior_imped_imag - menor_imped_imag)


def divider(data):

    res = {}

    for data_element in data:
        if data_element[1]['eletrodo'] is None:
            pprint(data_element)

        if data_element[1]['eletrodo'] not in res:
            res[data_element[1]['eletrodo']] = [data_element]
        else:
            res[data_element[1]['eletrodo']].append(data_element)

    return res


def load(data_file):

    with open(data_file) as data_f:
        data_set = json.load(data_f)

    result_data = []
    for data in data_set:
        nums = np.array([data['frequency'],
                         data['impedance_real'],
                         data['impeance_imaginary']])
        letters = {'eletrodo': data['eletrodo'], 'analito': data['analito']}
        result_data.append([nums, letters])

    normalize(result_data)
    return divider(result_data)
