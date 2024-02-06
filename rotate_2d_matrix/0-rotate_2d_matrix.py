#!/usr/bin/python3
""" 0-rotate_2d_matrix module """


def rotate_2d_matrix(matrix):
    """function that can rotate 2D NxN
    matrix 90 degrees clockwise in place"""
    n = len(matrix)

    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    for i in range(n):
        matrix[i] = matrix[i][::-1]
