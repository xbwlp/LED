from PIL import Image     #矩阵转图片使用
import matplotlib.image as img
import numpy as np
import math

# img = img.imread("lena.jpg")
# print(img)

def mapp(sita, h,a):
    x = math.cos(sita)*a
    if sita<pi:
        y = (h-a*(1-math.sin(sita)))/(2^0.5)
    if sita>=pi:
        y = -(h-a*(1-math.sin(sita)))/(2^0.5)
    return x,y
test = [[range(34)] * 24] * 360
print(len(test))



class map(object):
    def __init__(self,h,rad,a,hz,div):
        self.h = h
        self.w = 2*math.pi * rad
        self.a = a
        self.hz = hz
        self.div = div
        self.t = math.pi/div/self.w

    def mapp(self,n,h):
        x = math.cos(self.t * n*self.w) * self.a
        if self.t * n < math.pi:
            y = (h - self.a * (1 - math.sin(self.t * n*self.w))) / (1.414)
        if self.t * n >= math.pi:
            y = -(h - self.a * (1 - math.sin(self.t * n*self.w))) / (1.414)
        return x, y

    def read(self, test):
        pic = []
        for i in range(len(test)):
            row = []
            for j in range(2 * self.dev):
                col = []
                for k in range(self.h):
                    col.append(test[self.mapp(j,k)[0]][self.mapp(j,k)[1]])
                row.append(col)
            pic.append(row)


        return 0




map = map(len(test[0])/2,120,len(test[0])/2,24,30)
#print(map.t)
print(map.mapp(15,0))

