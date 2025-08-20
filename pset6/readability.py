from cs50 import get_string

def main():
    text = get_string("Text: ")

    words = countWords(text)
    letters = countLetters(text)

    print(words)
    print(letters)

def countWords(text):
    wordCount = 0
    for char in text:
        if char.isspace() or char == ".":
            wordCount += 1
            
    return wordCount


def countLetters(text):
    letters = [char for char in text if char.isalpha()]
    return len(letters)

main()
