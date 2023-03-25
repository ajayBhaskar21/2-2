import cv2

# Load the fingerprint image
img = cv2.imread('LT1.bmp', 0)

# Apply a Gaussian blur to reduce noise
img = cv2.GaussianBlur(img, (5, 5), 0)

# Apply a threshold to binarize the image
ret, img = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY_INV)

# Find the minutiae points using the Harris corner detector
minutiae_img = cv2.cornerHarris(img, 2, 3, 0.04)

# Threshold the minutiae image to extract the points
minutiae_img[minutiae_img < 0.01 * minutiae_img.max()] = 0
minutiae_img[minutiae_img >= 0.01 * minutiae_img.max()] = 255

# Display the original image and the minutiae points
cv2.imshow('Original Image', img)
cv2.imshow('Minutiae Points', minutiae_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
