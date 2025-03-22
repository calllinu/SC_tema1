# Algoritmi de criptare
Tema 1 include implementarea a doi algoritmi clasici de cifrare:
- Cifru de substituție: Inlocuim fiecare caracter din textul simplu cu un alt caracter conform unui sistem predefinit.
- Cifru de transpunere: Rearanjam caracterele din textul simplu în conformitate cu un sistem predefinit.

## Algoritmul lui Caesar

### Descriere

Cifrul Caesar este o metodă simplă de criptare care presupune mutarea fiecărei litere dintr-un mesaj cu un număr fix de poziții în alfabet. Acesta reprezintă un exemplu de cifru de substituție monoalfabetic, unde deplasarea literelor se face în funcție de o cheie numerică.

### Rulare program

1. Compilați cu Instructiune:
```powershell
gcc caesar_cipher.c -o caesar_cipher.exe
```
2. Parametri:  `-e` pentru criptare sau `-d` pentru decriptare, fișierul input, cheia și fișierul output (valabil pentru ambii algoritmi) 
```powershell
./caesar_cipher -e input.txt -k 3 -o output.txt
```
- `-e`: Criptare
- `-d`: Decriptare
- `-k`: Cheia (int)
- `-o`: Fișierul output
- 
### Tests

**Test 1**

Comandă: (din folderul /caesar)
```powershell
./caesar_cipher -e input.txt -k 3000 -o output.txt
```
Fișierul input.txt:
```
Securitatea și criptografia sunt esențiale pentru protejarea informațiilor în era digitală. Criptografia presupune utilizarea unor tehnici matematice pentru a ascunde conținutul unui mesaj, astfel încât doar persoanele autorizate să poată accesa sau înțelege informația. Aceasta joacă un rol crucial în protejarea datelor personale, financiare și de comunicație pe internet. Securitatea, pe de altă parte, se referă la măsurile adoptate pentru a preveni accesul neautorizat la sisteme și informații, asigurând astfel confidențialitatea, integritatea și disponibilitatea acestora.
```
Fișierul output.txt:
```
Comebsdkdok cs mbszdyqbkpsk cexd ocoxdskvo zoxdbe zbydotkbok sxpybwkdssvyb sx obk nsqsdkvk. Mbszdyqbkpsk zbocezexo edsvsjkbok exyb dorxsms wkdowkdsmo zoxdbe k kcmexno myxdsxedev exes wockt, kcdpov sxmkd nykb zobcykxovo kedybsjkdo ck zykdk kmmock cke sxdovoqo sxpybwkdsk. Kmokcdk tykmk ex byv mbemskv sx zbydotkbok nkdovyb zobcyxkvo, psxkxmskbo cs no mywexsmkdso zo sxdobxod. Comebsdkdok, zo no kvdk zkbdo, co bopobk vk wkcebsvo knyzdkdo zoxdbe k zbofoxs kmmocev xokedybsjkd vk cscdowo cs sxpybwkdss, kcsqebkxn kcdpov myxpsnoxdskvsdkdok, sxdoqbsdkdok cs nsczyxslsvsdkdok kmocdybk.
```

**Test 2**

Comandă:
```powershell
./caesar_cipher -d input.txt -k 3000 -o output.txt
```
Fișierul input.txt:
```
Comebsdkdok cs mbszdyqbkpsk cexd ocoxdskvo zoxdbe zbydotkbok sxpybwkdssvyb sx obk nsqsdkvk. Mbszdyqbkpsk zbocezexo edsvsjkbok exyb dorxsms wkdowkdsmo zoxdbe k kcmexno myxdsxedev exes wockt, kcdpov sxmkd nykb zobcykxovo kedybsjkdo ck zykdk kmmock cke sxdovoqo sxpybwkdsk. Kmokcdk tykmk ex byv mbemskv sx zbydotkbok nkdovyb zobcyxkvo, psxkxmskbo cs no mywexsmkdso zo sxdobxod. Comebsdkdok, zo no kvdk zkbdo, co bopobk vk wkcebsvo knyzdkdo zoxdbe k zbofoxs kmmocev xokedybsjkd vk cscdowo cs sxpybwkdss, kcsqebkxn kcdpov myxpsnoxdskvsdkdok, sxdoqbsdkdok cs nsczyxslsvsdkdok kmocdybk.
```
Fișierul output.txt:
```
Securitatea si criptografia sunt esentiale pentru protejarea informatiilor in era digitala. Criptografia presupune utilizarea unor tehnici matematice pentru a ascunde continutul unui mesaj, astfel incat doar persoanele autorizate sa poata accesa sau intelege informatia. Aceasta joaca un rol crucial in protejarea datelor personale, financiare si de comunicatie pe internet. Securitatea, pe de alta parte, se refera la masurile adoptate pentru a preveni accesul neautorizat la sisteme si informatii, asigurand astfel confidentialitatea, integritatea si disponibilitatea acestora.
```

## Cifru transpunere pe coloane

### Descriere

Cifrul de transpunere pe coloane presupune reorganizarea caracterelor unui mesaj pe baza unui număr de coloane definit printr-o cheie. Textul este introdus într-o matrice, organizat pe rânduri, iar rezultatul criptat se obține citind matricea pe coloane.

### Rulare program

1. Compilați cu Instructiunea:
```powershell
gcc transpunere.c -o transpunere.exe 
```
### Exemplu: ca caracter de umplere am selectat ('X')

### Tests

**Test 1**

Instructiune:  (din folderul /transpunere)
```powershell
./transpunere -e input.txt -k 3 -o output.txt 
```
Fișierul input.txt:
```
Securitatea si criptografia sunt esentiale pentru protejarea informatiilor in era digitala. Criptografia presupune utilizarea unor tehnici matematice pentru a ascunde continutul unui mesaj, astfel incat doar persoanele autorizate sa poata accesa sau intelege informatia. Aceasta joaca un rol crucial in protejarea datelor personale, financiare si de comunicatie pe internet. Securitatea, pe de alta parte, se refera la masurile adoptate pentru a preveni accesul neautorizat la sisteme si informatii, asigurand astfel confidentialitatea, integritatea si disponibilitatea acestora.
```
Fișierul output.txt:
```
Sutescpgf nena nurer fmioie ga.rtripsu izeurei tacpt aueoit uma tlnto ralaozeaoacss te fmi etjcur uaiptaaal rnefaieieonaeenrtSute   tpt  faaaredteerare cunuralsteinrt,sunaf ndtlaaieit  sniteasreraairtriststlpt ojeioairnrdil ioaarunulaan hcmeteerasn nnuuiejaf c apsneura  a caaiegioaaAaaoanocclnrer topsa,ina   mit  tn.eraapdaaaesre  si oa nu enaeletitaie  fmi irdsecfeiit,ngtesdpilaactacit  ioaau eieerptaanrtl  aitaCpgf epetir otniami nu cdctuln s,seiadreoe titsptae unlenrt.cs a  lri  ojedereol ncrsdcucipiee cit,eel r,eerlmulaptpt pvics aoz  smsioaiaga tloinate traaiiobit eo.
```

**Test 2**

Instructiune:
```powershell
./transpunere -d input.txt -k 3 -o output.txt
```
Fișierul input.txt:
```
Sutescpgf nena nurer fmioie ga.rtripsu izeurei tacpt aueoit uma tlnto ralaozeaoacss te fmi etjcur uaiptaaal rnefaieieonaeenrtSute   tpt  faaaredteerare cunuralsteinrt,sunaf ndtlaaieit  sniteasreraairtriststlpt ojeioairnrdil ioaarunulaan hcmeteerasn nnuuiejaf c apsneura  a caaiegioaaAaaoanocclnrer topsa,ina   mit  tn.eraapdaaaesre  si oa nu enaeletitaie  fmi irdsecfeiit,ngtesdpilaactacit  ioaau eieerptaanrtl  aitaCpgf epetir otniami nu cdctuln s,seiadreoe titsptae unlenrt.cs a  lri  ojedereol ncrsdcucipiee cit,eel r,eerlmulaptpt pvics aoz  smsioaiaga tloinate traaiiobit eo.
```
Fișierul output.txt:
```
Securitatea si criptografia sunt esentiale pentru protejarea informatiilor in era digitala. Criptografia presupune utilizarea unor tehnici matematice pentru a ascunde continutul unui mesaj, astfel incat doar persoanele autorizate sa poata accesa sau intelege informatia. Aceasta joaca un rol crucial in protejarea datelor personale, financiare si de comunicatie pe internet. Securitatea, pe de alta parte, se refera la masurile adoptate pentru a preveni accesul neautorizat la sisteme si informatii, asigurand astfel confidentialitatea, integritatea si disponibilitatea acestora.
```
