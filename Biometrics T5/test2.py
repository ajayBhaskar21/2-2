import cv2

# Read the color image
image = cv2.imread("images\waterfall1.jpg")

# Convert the image to grayscale
grayscale_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Save or display the grayscale image

cv2.imshow("Grayscale Image", grayscale_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
