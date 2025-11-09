## EX 13 : IMPLEMENTATION OF MESSAGE AUTHENTICATION CODE(MAC)

## AIM:

To implement a Message Authentication Code (MAC) using a shared secret key and a hash function to verify the integrity and authenticity of a message.

## ALGORITHM:

1. Choose a shared secret key that will be known to both the sender and the receiver.
2. Define the message that needs to be authenticated.
3. Concatenate the message and the secret key to form a new string.
4. Apply a hash function (e.g., simple XOR-based hash or any secure hashing function like SHA) to the concatenated string to generate the MAC.
5. Send the message along with the generated MAC.
6. For verification, the receiver uses the same shared key, concatenates it with the received message, and applies the hash function to generate a new MAC.
7. Compare the generated MAC with the received MAC. If they match, the message is authentic; otherwise, it has been tampered with.

## PROGRAM:

```c
#include <stdio.h>
#include <string.h>

unsigned char generateMAC(char message[], char key[]) {
    unsigned char mac = 0;
    int i;

    for (i = 0; i < strlen(message); i++)
        mac ^= message[i];

    for (i = 0; i < strlen(key); i++)
        mac ^= key[i];

    return mac;
}

int main() {
    char message[100], receivedMessage[100], key[50];
    unsigned char mac, receivedMAC, newMAC;

    printf("Enter the message: ");
    scanf("%s", message);

    printf("Enter the shared secret key: ");
    scanf("%s", key);

    mac = generateMAC(message, key);
    printf("\nGenerated MAC: %u\n", mac);

    printf("\n--- Receiver Side ---\n");
    printf("Enter the received message: ");
    scanf("%s", receivedMessage);

    printf("Enter the received MAC: ");
    scanf("%hhu", &receivedMAC);

    newMAC = generateMAC(receivedMessage, key);

    if (newMAC == receivedMAC)
        printf("\nMessage is authentic and unaltered.\n");
    else
        printf("\nMessage integrity verification failed.\n");

    return 0;
}
```

## OUTPUT:

![alt text](image.png)

## RESULT:

The Message Authentication Code (MAC) was implemented successfully, allowing the verification of message integrity and authenticity using a shared secret key.
