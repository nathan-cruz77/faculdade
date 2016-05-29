import numpy as np

from loader import load

FOLDS = 100


def distance(a, b):
    '''Euclidian distance'''

    return np.linalg.norm(a - b)


def most_common(lista):
    return max(set(lista), key=lista.count)


def knn(k, training_data, test):

    training_data = list(training_data)

    distances = np.array([distance(i[0], test) for i in training_data])
    nearest = [training_data[i][1]['analito'] for i in np.argsort(distances)[::-1][:k]]

    return most_common(nearest)


if __name__ == '__main__':

    data = load('data.json')

    Ks = []
    acc = []

    K = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]

    for j, k in enumerate(K):

        test_data = []
        training_data = []

        for _, v in data.items():
            np.random.shuffle(v)
            test_data.extend(v[:len(v) // FOLDS])
            training_data.extend(v[(len(v) // FOLDS) + 1:])

        accuracy = 0

        for i, test_element in enumerate(test_data):
            trainning = [x for x in training_data if x[1]['eletrodo'] == test_element[1]['eletrodo']]

            if knn(k, trainning, test_element[0]) == test_element[1]['analito']:
                accuracy += 1

            print('\r{:.2f}%'.format((i + 1) * 100 / len(test_data)), end='')

        Ks.append(k)
        acc.append((accuracy * 100.) / len(test_data))

        print('\naccuracy = {:.3f}%'.format((accuracy * 100.) / len(test_data)))
        print('k = {}'.format(k))
        print('{:.2f}% <extern loop>\n'.format((j + 1) * 100. / len(K)))

    acc = np.array(acc)
    print('Best accuracy: {:.3f}%'.format(np.max(acc)))
    print('Best k: {}'.format(Ks[np.argmax(acc)]))