# embededSoftware

## Lecture fichier .ubx

Les données en entrée sont :

```
b562 0121 1400 3006 9d1d 1100 0000 36b5
0300 e007 0401 1200 0d07 3724 b562 0210
1001 3106 9d1d 6207 0b00 02ae 8cbd 8d60
60c1 b2c8 dd00 1d8c 7541 b2e6 fa44 0407
```

D'après la documentation https://www.u-blox.com/sites/default/files/products/documents/u-blox6_ReceiverDescrProtSpec_%28GPS.G6-SW-10018%29_Public.pdf

on en extrait les octes correspondant aux :

 - jour
 - mois
 - anne
 - heure
 - minute
 - seconde
 - milliseconde
 - nanoseconde
 - validite

 On traduit leurs valeurs hexadécimales en décimales

## Ecriture du fichier .csv

On écrit toutes nos infos dans un fichier time.csv en les séparant par des virgules

Ci dessous un extrait du csv : 

```csv
jour,mois,anne,heure,minute,seconde,milliseconde,nanoseconde,validite
1,4,2016,18,0,13,496830000,242998,7
1,4,2016,18,0,43,496860000,228157,7
```