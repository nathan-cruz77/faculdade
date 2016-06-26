import random
import sys
from pprint import pprint
from collections import Counter
from math import log2

from util import load_data_id3
from util import most_common
from util import is_continuous
from util import nearest


# TEST_SIZE = 1000
# PRECISION = 5


def entropy(data):
    n = len(data)
    return sum(-1 *  (v / n) * log2(v / n) for _, v in Counter(data).items())


class Node:

    def __init__(self, splitter):
        self.attr = splitter
        self.sons = {}

    def add_son(self, son):
        self.sons.update(son)


class Leaf:

    def __init__(self, answer):
        self.answer = answer


def id3(data):
    if all(x['analito'] == 'glicose' for x in data):
        return Leaf('glicose')

    if all(x['analito'] == 'triglicerideo' for x in data):
        return Leaf('triglicerideo')

    if len([k for k in data[0].keys() if k != 'analito']) <= 0:
        return Leaf(most_common([d['analito'] for d in data]))

    # Entropia dos atributos
    splited = {k: entropy([x[k] for x in data.copy()]) for k in data[0].keys()}
    splited.pop('analito')

    # Atributo separador
    separator = min(splited.items(), key=lambda x: x[1])[0]
    node = Node(separator)

    if is_continuous(data[0][separator]):
        for x in data:
            x[separator] = round(x[separator], PRECISION)

    for v in set(x[separator] for x in data):
        aux = [x for x in data.copy() if separator in x and x[separator] == v]
        for i in aux:
            i.pop(separator)

        node.add_son({v: id3(aux)})

    return node


def predict(element, tree):
    if type(tree) is Leaf:
        return tree.answer

    if is_continuous(element[tree.attr]):
        return predict(element, tree.sons[nearest(element[tree.attr],
                                                  list(tree.sons.keys()),
                                                  precision=PRECISION)])

    return predict(element, tree.sons[element[tree.attr]])


if __name__ == '__main__':

    PRECISION = int(sys.argv[1])

    data = load_data_id3('data.json')
    TEST_SIZE = len(data) // 10
    random.shuffle(data)

    total = len(data)
    test_data, trainning_data = data[:TEST_SIZE], data[TEST_SIZE + 1:]

    pah_gox_data = [x for x in trainning_data if x['eletrodo'] == 'PAH_GOX']
    pah_lipase_data = [x for x in trainning_data if x['eletrodo'] == 'PAH_lipase']

    id3_trees = {
        'PAH_lipase': id3(pah_lipase_data),
        'PAH_GOX': id3(pah_gox_data)
    }

    hit_glicose, hit_triglicerideo = 0, 0
    miss_glicose, miss_triglicerideo = 0, 0

    total_glicose = len([l for l in test_data if l['analito'] == 'glicose'])
    total_triglicerideo = len([l for l in test_data if l['analito'] == 'triglicerideo'])

    for test_element in test_data:
        pred = predict(test_element, id3_trees[test_element['eletrodo']])

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
