print("The original (padded) message is:")

message = "No one has completed lab 2 so give them all a 0"
message_hex = ''.join('{:02x}'.format(x) for x in message.encode('ascii'))
print(message_hex, end="")

print("80", end="")
for i in range(62):
    print("00", end="")

print("01f8")