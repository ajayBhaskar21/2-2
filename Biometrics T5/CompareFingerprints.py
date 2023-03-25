import cv2

# Load the fingerprint images
img1 = cv2.imread('LT1.bmp', 0)
img2 = cv2.imread('RI2.bmp', 0)

# Extract minutiae points using Harris corner detector
minutiae_img1 = cv2.cornerHarris(img1, 2, 3, 0.04)
minutiae_img2 = cv2.cornerHarris(img2, 2, 3, 0.04)

# Threshold the minutiae images to extract the points
minutiae_img1[minutiae_img1 < 0.01 * minutiae_img1.max()] = 0
minutiae_img1[minutiae_img1 >= 0.01 * minutiae_img1.max()] = 255
minutiae_img2[minutiae_img2 < 0.01 * minutiae_img2.max()] = 0
minutiae_img2[minutiae_img2 >= 0.01 * minutiae_img2.max()] = 255

# Extract the minutiae points
features1 = cv2.findNonZero(minutiae_img1)
features2 = cv2.findNonZero(minutiae_img2)

# Perform fingerprint matching using Euclidean distance
distances = cv2.matchShapes(features1, features2, cv2.CONTOURS_MATCH_I1, 0.0)
if distances < 1:
    print('Fingerprints match')
else:
    print('Fingerprints do not match')
