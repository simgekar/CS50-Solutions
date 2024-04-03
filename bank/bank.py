greetings = input("Greeting: ").strip().lower()

if "hello" in greetings:
    print("$0")
elif greetings[0] == "h":
    print("$20")
else:
    print("$100")
