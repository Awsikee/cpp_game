from PIL import Image
import os

def create_spritesheet(images, output_path):
    images = [Image.open(image) for image in images]

    # Assuming all images have the same size
    width, height = images[0].size

    spritesheet = Image.new("RGBA", (width, height* len(images)))

    for i, image in enumerate(images):
        spritesheet.paste(image, (0,i * height))
    return spritesheet


def main():
    # Get all .png files in the current working directory
    images = ["walk_front.png", "walk_back.png", "walk_left.png", "walk_right.png"]

    if not images:
        print("No .png images found in the working directory.")
        return

    spritesheet_path = os.getcwd()

    # Create spritesheet
    spritesheet_with_transparency = create_spritesheet(images, spritesheet_path)

    # Change black to transparency in the spritesheet
    #spritesheet_with_transparency = change_black_to_transparency(spritesheet_path)

    # Save the final spritesheet with transparency
    spritesheet_with_transparency.save('full_spritesheet.png')
    print("Spritesheet with transparency saved: spritesheet_with_transparency.png")

if __name__ == "__main__":
    main()