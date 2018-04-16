#!/usr/bin/env python
# coding=utf-8
import numpy as np
# c_im ,c -- channel
def im2col (data_im):
    c_im,h_im,w_im = data_im.shape
    h_col = h_im - 2 + 1
    w_col = w_im - 2 + 1
    c_col = c_im * 2 * 2
    data_col = np.zeros((h_col * w_col, c_col),dtype = np.int32)
    for c in range(c_col):
        w_offset = c % 2    # 
        h_offset = (c / 2) % 2
        c_offset = c / 2 / 2    
        
        for h in range(h_col):
            for w in range (w_col):
                h_pad = h + h_offset
                w_pad = w + w_offset 
                data_col[h * w_col + w, c] = data_im[c_offset, h_pad, w_pad]

    return data_col 
# kernel 2*2 stride 1, pad 0
# data_im snape:channel height wide(3 * 3 * 3)
# data_col shape:height * width channel

if __name__ == '__main__':
    input_data = np.array([[[1, 2, 0],
                            [1, 1, 3],
                            [0, 2, 2]],
                                    [[0, 2, 1],
                                    [0, 3, 2],
                                    [1, 1, 0]],
                                            [[1, 2, 1],
                                             [0, 1, 3],
                                             [3, 3, 2]]])
    convolution_kernels = np.array([[[[1, 1],
                                      [2, 2]],
                                            [[1, 1],
                                             [1, 1]],
                                                   [[0, 1],
                                                    [1, 0]]],
                                    [[[1, 0],
                                      [0, 1]],
                                            [[2, 1],
                                             [2, 1]],
                                                   [[1, 2],
                                                    [2, 0]]]])
    input_features = im2col(input_data);
    print(input_features);
    kernel_matrix = (np.reshape(convolution_kernels, (2, -1))).T

    print(kernel_matrix);
    output_features = np.dot(input_features, kernel_matrix)
    print(output_features)
    
    h_in, w_in, c_in = input_data.shape
    h_out = h_in - 2 + 1
    w_out = w_in - 2 + 1
    out_data = np.zeros((2, 2, 2), dtype=np.int32)
#    for k in range(2):
#        for h in range(w_out):
#            for c in range(c_in):
#                for p in range(2):
#                    for q in range(2):
#
                        #out_data[k, h, w] += input_data[c, h + p, w + q] * convolution_kernels[k, c, p, q]
    #print(out_data)
    # print("OK\n");
