import matplotlib.pyplot as plt
import imageio.v2 as imageio

# Read the image
i = imageio.imread('images\waterfall1.jpg')

# Display the original image
plt.subplot(3, 2, 1)
plt.imshow(i)
plt.title('Original image')

# Extract the red component
r = i[:, :, 0]
plt.subplot(3, 2, 2)
plt.imshow(r, cmap='gray')  # Display as grayscale
plt.title('Red Component')

# Extract the green component
g = i[:, :, 1]
plt.subplot(3, 2, 3)
plt.imshow(g, cmap='gray')
plt.title('Green Component')

# Extract the blue component
b = i[:, :, 2]
plt.subplot(3, 2, 4)
plt.imshow(b, cmap='gray')
plt.title('Blue Component')

# Adjust subplot spacing
plt.tight_layout()

# Show the plots
plt.show()
