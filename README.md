Programos versijoje 1.1 kode buvusi struktūra pakeista klase, ko pasakoje buvo šiektiek pakeistos kaikurios kodo vietos. Nauja programa buvo ištestuota ir palyginta su buvusia, o paskui atlikta analizė į makefile įdėtų flag'ų O1, O2, O3 įtaką kodui.

100 000 studentų:
|          Veiksmas          |    Sruktūra      |      Klasė        |
|----------------------------|------------------|-------------------|
| Failo nuskaitymas          |     0.19s        |      0.23s        |
| Failo rikiavimas           |     0.47s        |      0.74s        |
| Failo rusiavimas           |     0.01s        |      0.00s        |
| Failo išvedimas            |     0.41s        |      0.37s        |
| Programos veikimo laikas   |     1.06s        |      1.33s        |

1 000 000 studentų:
|          Veiksmas          |    Sruktūra      |      Klasė        |
|----------------------------|------------------|-------------------|
| Failo nuskaitymas          |     2.29s        |      2.60s        |
| Failo rikiavimas           |     8.58s        |      9.12s        |
| Failo rusiavimas           |     0.25s        |      0.01s        |
| Failo išvedimas            |     4.12s        |      3.89s        |
| Programos veikimo laikas   |     15.00s       |      15.61s       |

Sekantys tyrimai naudojant flag'us buvo atlikti tik klasę turinčiam kodui:

O1:
| Studentų skaičius:         |    100 000       |    1 000 000      |
|----------------------------|------------------|-------------------|
| Failo nuskaitymas          |     0.22s        |      2.36s        |
| Failo rikiavimas           |     0.66s        |      7.93s        |
| Failo rusiavimas           |     0.00s        |      0.01s        |
| Failo išvedimas            |     0.35s        |      4.14s        |
| Programos veikimo laikas   |     1.23s        |      14.43s       |

O2:
| Studentų skaičius:         |    100 000       |    1 000 000      |
|----------------------------|------------------|-------------------|
| Failo nuskaitymas          |     0.24s        |      2.42s        |
| Failo rikiavimas           |     0.61s        |      7.58s        |
| Failo rusiavimas           |     0.00s        |      0.01s        |
| Failo išvedimas            |     0.43s        |      4.14s        |
| Programos veikimo laikas   |     1.27s        |      14.14s       |

O3:
| Studentų skaičius:         |    100 000       |    1 000 000      |
|----------------------------|------------------|-------------------|
| Failo nuskaitymas          |     0.20s        |      2.27s        |
| Failo rikiavimas           |     0.63s        |      7.43s        |
| Failo rusiavimas           |     0.00s        |      0.01s        |
| Failo išvedimas            |     0.38s        |      4.12s        |
| Programos veikimo laikas   |     1.22s        |      13.83s       |

Išvada: programos trukmė nuo pasirinkto optimizavimo būdo kinta labai neženkliai, kuo didesnis failas, tuo aukštesnis optimizavimo būdas neženkliai pagreitina programos spartą.

