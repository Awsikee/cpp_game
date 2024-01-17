from PIL import Image

def convert_white_to_transparent(image_path):
    # Open the image using Pillow
    image = Image.open(image_path)

    # Convert the image to RGBA mode (if not already)
    image = image.convert("RGBA")

    # Get the pixel data of the image
    pixel_data = image.load()

    # Iterate over each pixel
    for y in range(image.height):
        for x in range(image.width):
            # Get the RGB values of the pixel
            r, g, b, a = pixel_data[x, y]

            # Check if the pixel is white (RGB value of 255, 255, 255)
            if r == 255 and g == 255 and b == 255:
                # Set the alpha channel of the pixel to 0 (transparent)
                pixel_data[x, y] = (r, g, b, 0)

    # Save the modified image with transparency
    image.save("collider.png")

# Call the function and provide the path to your image file
convert_white_to_transparent("collider.png")
