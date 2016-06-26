import sys
import math
import random
import functools

from util import load_data_knn
from util import most_common


def distance(a, b):
    '''Euclidian distance'''
    return math.sqrt((b['frequency'] - a['frequency']) ** 2 +
                     (b['impedance_real'] - a['impedance_real']) ** 2 +
                     (b['impedance_imaginary'] - a['impedance_imaginary']) ** 2)


def knn(k, training_data, test_element):
    distances = [(i, distance(i, test_element)) for i in training_data]
    nearest = sorted(distances, key=lambda x: x[1])[:k]

    return most_common([x[0]['analito'] for x in nearest])


if __name__ == '__main__':

    data = load_data_knn('data.json')
    TEST_SIZE = 100 # len(data) // 10

    ks = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
          37, 41, 43, 47, 53, 59, 61, 67, 71]

    k = 2
    # for k in ks:
    # accs = []

    # for asd in range(20):
    random.shuffle(data)

    test_data = data[:TEST_SIZE]
    trainning_data = {
        'PAH_lipase': [x for x in data[TEST_SIZE + 1:] if x['eletrodo'] == 'PAH_lipase'],
        'PAH_GOX': [x for x in data[TEST_SIZE + 1:] if x['eletrodo'] == 'PAH_GOX']
    }

    hit_glicose, hit_triglicerideo = 0, 0
    miss_glicose, miss_triglicerideo = 0, 0

    total_glicose = len([l for l in test_data if l['analito'] == 'glicose'])
    total_triglicerideo = len([l for l in test_data if l['analito'] == 'triglicerideo'])

    for test_element in test_data:
        pred = knn(k, trainning_data[test_element['eletrodo']], test_element)

        if pred == test_element['analito']:
            if pred == 'glicose':
                hit_glicose += 1
            else:
                hit_triglicerideo += 1
        else:
            if pred == 'glicose':
                miss_triglicerideo += 1
            else:
                miss_glicose += 1


    accuracy_glicose = (hit_glicose / total_glicose) * 0.5
    accuracy_triglicerideo = (hit_triglicerideo / total_triglicerideo) * 0.5
    accuracy = accuracy_triglicerideo + accuracy_glicose

    total = len(data)

    print('Acurácia ponderada = {:.3f}'.format(accuracy))
    print('Precisão total = {:.3f}'.format((hit_glicose + hit_triglicerideo) / total))
    print()

    print('Cobertura(g) = {:.3f}'.format((hit_glicose + miss_triglicerideo) / total))
    print('Cobertura(t) = {:.3f}'.format((hit_triglicerideo + miss_glicose) / total))
    print()

    # Blablabla que o professor pediu...
    print('Sensitividade(g) = {:.3f}'.format(hit_glicose / total_glicose))
    print('Sensitividade(t) = {:.3f}'.format(hit_triglicerideo / total_triglicerideo))
    print()

    print('Suporte(g) = {:.3f}'.format(hit_glicose / total))
    print('Suporte(t) = {:.3f}'.format(hit_triglicerideo / total))
    print()

    print('Confiabilidade(g) = {:.3f}'.format(hit_glicose / (hit_glicose + miss_triglicerideo)))
    print('Confiabilidade(t) = {:.3f}'.format(hit_triglicerideo / (hit_triglicerideo + miss_glicose)))
    print()

    print('Especificidade(g) = {:.3f}'.format(miss_glicose / total_glicose))
    print('Especificidade(t) = {:.3f}'.format(miss_triglicerideo / total_triglicerideo))
    print()
