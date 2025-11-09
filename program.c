#include <stdio.h>
#include <string.h>

unsigned char generateMAC(char message[], char key[])
{
    unsigned char mac = 0;
    int i;

    for (i = 0; i < strlen(message); i++)
        mac ^= message[i];

    for (i = 0; i < strlen(key); i++)
        mac ^= key[i];

    return mac;
}

int main()
{
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
