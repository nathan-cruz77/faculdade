import json
import sys

import numpy as np

ANSWER_FIELD = 'analito'
FOLDS = 10.0


def vectorize_data(data_file):
    with open(data_file) as data_f:
        data_set = json.load(data_f)

    result_data = []
    for data in data_set:
        result_data.append([
                data['frequency'],
                data['impedance_real'],
                data['impeance_imaginary'],
                data['eletrodo'],
                data['analito']
        ])

    tipo = np.dtype([
            ('frequency', np.float_),
            ('impedance_real', np.float_),
            ('impedance_imaginary', np.float_),
            ('eletrodo', 'S20'),
            ('analito', 'S20')
        ])

    return np.array([tuple(i) for i in result_data], dtype=tipo)


def distance(a, b):
    '''Euclidian distance'''

    a = a.copy()
    b = b.copy()

    tipo = np.dtype([
            ('frequency', np.float_),
            ('impedance_real', np.float_),
            ('impedance_imaginary', np.float_)
    ])

    if a[3] != b['eletrodo']:
        return float('inf')

    a = np.array([a[0], a[1], a[2]])
    b = np.array([b['frequency'], b['impedance_real'], b['impedance_imaginary']])

    return np.linalg.norm(a - b)


def most_common(lst):
    return max(set(lst), key=lst.count)


def knn(k, training_data, test):

    tipo = np.dtype([
            ('frequency', np.float_),
            ('impedance_real', np.float_),
            ('impedance_imaginary', np.float_),
            ('eletrodo', 'S20')
    ])

    test_data = np.array(tuple(test), dtype=tipo)
    distances = np.array([distance(i, test_data) for i in training_data])

    nearest = []
    for i in np.argsort(distances)[::-1][:k]:
        nearest.append(training_data[i][4])

    return most_common(nearest)


if __name__ == '__main__':
    data = vectorize_data('data.json')

    Ks = []
    acc = []
    for x in range(50):
        np.random.shuffle(data)
        test_data = data[:round(len(data) / FOLDS)]
        training_data = data[round(len(data) / FOLDS) + 1:]

        k = np.random.randint(1, len(training_data) + 1)
        accuracy = 0
        for i, test_element in enumerate(test_data):
            resp = knn(k, training_data, [test_element[0], test_element[1],
                                          test_element[2], test_element[3]])

            if resp == test_element[4]:
                accuracy += 1

            print('\r{:.2f}%'.format((i + 1) * 100 / len(test_data)), end='')

        Ks.append(k)
        acc.append(accuracy * 100. / len(test_data))
        print('\n{:.2f}% <extern loop>'.format(x * 100. / len(training_data)))

    acc = np.array(acc)
    print('Best accuracy: {:.3f}%'.format(np.max(acc)))
    print('Best k: {}'.format(Ks[np.argmax(acc)]))
