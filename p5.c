#include <stdio.h>
#include <stdlib.h>

int max(int arr[], int n) {
    if (n==1) {
        return arr[0];
    }
    return arr[n-1] > max(arr, n-1) ? arr[n-1] : max(arr, n-1);
}

int min(int arr[], int n) {
    if(n==1) {
        return arr[0];
    }
    return arr[n-1] < min(arr, n-1) ? arr[n-1] : min(arr, n-1);
}

int main()
{
    int n, i;
    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &n);
    int arr[n];
    printf("Introduceti elementele vectorului: ");
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    printf("Cel mai mic numar din vector este: %d\n", max(arr, n));
    printf("Cel mai mare numar din vector este: %d\n", min(arr, n));
    return 0;
}

/* Cele 2 functii recursive parcurg vectorulul de elemente si salveaza cea mai mica respectiv cea mai mare valoare gasita.
Cand dimensiunea vectorului ajunge sa aiba un singur element acesta este verificat daca verifica sau nu conditia de maxim / minim
in cazul in care nu verifica functia va returna ultima valoare care verifica conditia. */
