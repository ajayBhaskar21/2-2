import cv2

# Read the image
image = cv2.imread('img1.jpg')

# Convert the image from BGR to RGB
image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

# Display the original image
plt.subplot(3, 2, 1)
plt.imshow(image)
plt.title('Original image')

# Split the image channels
b, g, r = cv2.split(image)

# Display the red component
plt.subplot(3, 2, 2)
plt.imshow(r, cmap='gray')
plt.title('Red Component')

# Display the green component
plt.subplot(3, 2, 3)
plt.imshow(g, cmap='gray')
plt.title('Green Component')

# Display the blue component
plt.subplot(3, 2, 4)
plt.imshow(b, cmap='gray')
plt.title('Blue Component')

# Adjust subplot spacing
plt.tight_layout()

# Show the plots
plt.show()
