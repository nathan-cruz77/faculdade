import json

import numpy as np

ANSWER_FIELD = 'analito'
MAX_K = 21000

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

    dist = 0

    tipo = np.dtype([
            ('frequency', np.float_),
            ('impedance_real', np.float_),
            ('impedance_imaginary', np.float_)
    ])

    if a[3] != b[3]:
        return float('inf')

    a = np.array([a[0], a[1], a[2]])
    b = np.array([b[0], b[1], b[2]])

    return np.linalg.norm(a - b)


def most_common(lst):
    return max(set(lst), key=lst.count)

def knn(k, training_data, test_data):

    test_data = np.array(test_data)
    distances = np.array([distance(i, test_data) for i in training_data])

    nearest = []
    for i in np.argsort(distances)[::-1][:k]:
        nearest.append(training_data[i][4])

    return most_common(nearest)


if __name__ == '__main__':
    training_data = vectorize_data('data.json')

    for i in range(1, MAX_K):
        resp = knn(i, training_data, [10000000.0, 55.09512, 62.78527, b'PAX_GOX'])

        if resp != b'glicose':
            print(resp)
        else:
            print('\r{:.2f}%'.format(i*100/21000), end='')
    print()
