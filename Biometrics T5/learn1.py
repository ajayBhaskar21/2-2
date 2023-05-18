import cv2
import numpy as np

i = cv2.imread('images\waterfall1.jpg')
j = cv2.imread('images\iris\img1.bmp')

matrix1 = cv2.cvtColor(i, cv2.COLOR_BGR2RGB)
matrix2 = cv2.cvtColor(j, cv2.COLOR_BGR2RGB)
cv2.imshow("Images", i)
cv2.imshow("Second Image", j)


result = np.array_equal(matrix1, matrix2)

print(result)


cv2.waitKey(0)
cv2.destroyAllWindows()
