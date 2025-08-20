from cs50 import get_string

def main():
    text = get_string("Text: ")

    words = countWords(text)
    letters = countLetters(text)

    print(words)
    print(letters)

def countWords(input_string):
    

def countLetters(input_string):
    letters = [char for char in input_string if char.isalpha()]
    return len(letters)

main()
