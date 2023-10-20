

# using huggingface module 
from datasets import load_from_disk

# get data from arrow file 
# dataset_name = "./wav_file/mel/marvin_mel/train/"
dataset_name = "./speech_command_v1/mel/zero_mel/train/"
dataset = load_from_disk(dataset_name)


import os

# specify the directory where you want to save the images
# new_dir = "./mel_image/house"
new_dir = "./speech_command_v1/image_mel/zero"

# create the directory if it doesn't exist
if not os.path.exists(new_dir):
    os.makedirs(new_dir)

# iterate over the dataset
for instance in dataset:
    image = instance['image']
    filename = instance['audio_file']

    # create filename for image using basename from audio_file
    image_filename = os.path.splitext(os.path.basename(filename))[0] + ".png"

    # create complete path for saving image
    save_path = os.path.join(new_dir, image_filename)
    
    # save the image as a PNG file in the specified directory
    image.save(save_path)

