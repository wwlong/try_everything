#!/usr/bin/env python
# coding=utf-8
import numpy as np
# feature shape: N
# label shape: N ,一维的
def softmaxWithLoss(feature, label):
        prob = np.exp(feature - np.max(feature, 0))
        prob = prob * 1.0 / np.sum(prob, 0);

        diff = np.zeros_like(prob, dtype=np.float32)
        Loss = 0 
        N = prob.shape[0]

        for i in range(N):
            gl = label[i]
            prob_i = prob[i]
            if gl == 0:
                diff[i] = prob_i
            else:
                Loss += -np.log(max(prob_i, 1.175494351e-38)) # 此处是个坑,注意
                diff[i] = prob_i - 1
        
        return Loss, diff 

if __name__ == '__main__':
    feature = np.array([1, 2, 3, 4, 10])
    label = np.array([1, 0, 0, 0, 0])
    Loss, diff = softmaxWithLoss(feature, label)
    print(Loss)
    print(diff)
