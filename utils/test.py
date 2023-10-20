
from datasets import load_dataset
from IPython.display import Audio

tedlium = load_dataset("LIUM/tedlium", "release1") # for Release 1

# see structure
print(tedlium)

# load audio sample on the fly
audio_input = tedlium["train"][0]["audio"]["array"]  # first decoded audio sample
transcription = tedlium["train"][0]["text"]  # first transcription


# sample rate 
sample_rate = 16000

# Audio(audio_input, rate=sample_rate)

print(audio_input)

