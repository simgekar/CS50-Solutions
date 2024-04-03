# TODO
text = input("Text: ")
letters = 0
sentences = 0

for i in range(len(text)):
    if text[i].isalpha() == True:
        letters += 1
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1

words = text.split()
words = len(words)

L = letters / words * 100
S = sentences / words * 100
index = 0.0588 * L - 0.296 * S - 15.8
index = round(index)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade: {index:.0f}")
