# 📌 Git Tahák pro Visual Studio Code (VS Code)

## **Základní Předpoklady**
- **Git** je nainstalovaný na tvém systému.
- **Visual Studio Code** je nainstalovaný a nakonfigurovaný.
- Máš nastavené uživatelské jméno a email v Gitu:
  ```bash
  git config --global user.name "Tvé Jméno"
  git config --global user.email "tvůj.email@example.com"
  ```
# 📂 Práce s Repozitářem

## **1. Inicializace Git Repozitáře**
***GUI:***
- Otevři VS Code a načti složku projektu (File > Open Folder...).
- Klikni na ikonu Source Control (ikona větvení) na levém panelu.
- Klikni na Initialize Repository.

***Terminál:***
```bash
git init
```
## **2. Klónování Repozitáře**
***GUI:***
- Otevři příkazovou paletu (Ctrl + Shift + P).
- Zadej Git: Clone a stiskni Enter.
- Vlož URL repozitáře a vyber cílovou složku.

***Terminál:***
```bash
git clone https://github.com/uživatel/název-repozitáře.git
```
# 📝 Základní Git Příkazy ve VS Code
## 1. Přidání Změn (Staging)
***GUI:***
V Source Control panelu klikni na + vedle jednotlivých souborů nebo na + v záhlaví pro přidání všech změn.

***Terminál:***
```bash
git add název_souboru
git add .
```
## **2. Commit Změn**
***GUI:***
- V Source Control panelu napiš zprávu commitu do pole nahoře.
- Stiskni Ctrl + Enter nebo klikni na ikonu zaškrtnutí (✔️).

***Terminál:***
  ```bash
  git commit -m "Popis commitu"
  ```
## **3. Push Změn na Remote Repozitář**
***GUI:***
- Klikni na tři tečky (⋯) v Source Control panelu a zvol Push.

***Terminál:***
```bash
git push origin main
(Nahraď main názvem tvé větve, pokud používáš jinou.)
```
## **4. Pull Změn z Remote Repozitáře**
***GUI:***
- Klikni na tři tečky (⋯) v Source Control panelu a zvol Pull.

***Terminál:***
```bash
git pull origin main
```

# 🌿 Práce s Větvemi
## **1. Vytvoření Nové Větve**
***GUI:***
- Klikni na aktuální větev v dolním levém rohu VS Code.
- Zvol Create new branch.
- Zadej název nové větve.

***Terminál:***
```bash
git branch název-větve
git checkout název-větve
```
Nebo zjednodušeně:
```bash
git checkout -b název-větve
```

## **2. Přepnutí na Jinou Větev**
***GUI:***
- Klikni na aktuální větev v dolním levém rohu a vyber požadovanou větev.

***Terminál:***
```bash
git checkout název-větve
```
## **3. Sloučení Větví (Merge)**
***GUI:***
- Přepni se na cílovou větev (např. main).
- Klikni na tři tečky (⋯) v Source Control panelu a zvol Merge Branch....
- Vyber větev, kterou chceš sloučit.

***Terminál:***
```bash
git checkout main
git merge název-větve
```

# 🔄 Řešení Konfliktů
## **1. Identifikace Konfliktů**
Konflikty se objeví po pokusu o sloučení větví nebo při pullu změn.

## **2. Řešení Konfliktů v VS Code**
VS Code zvýrazní konfliktní soubory v Source Control panelu.
Otevři soubor a vyber, kterou verzi chceš zachovat:
- Accept Current Change
- Accept Incoming Change
- Accept Both Changes
- Compare Changes

## **3. Po Vyřešení Konfliktů**
Přidej vyřešené soubory a proveď commit:

***Terminál:***
```bash
git add vyřešený_soubor
git commit -m "Vyřešení konfliktů"
```

# 🔧 Další Užitečné Příkazy
## **1. Zobrazení Statusu Repozitáře**
***GUI:***
Stav je viditelný přímo v Source Control panelu.

***Terminál:***
```bash
git status
```
## **2. Zobrazení Historie Commitů**
***GUI:***
Použij rozšíření jako GitLens pro podrobnější historii.

***Terminál:***
```bash
git log
```
## **3. Vrácení Změn**
***GUI:***
Klikni pravým tlačítkem na soubor v Source Control panelu a vyber Discard Changes.

***Terminál:***
```bash
git checkout -- název_souboru
```
## **4. Odstranění Souboru z Repozitáře**
***GUI:***
Klikni pravým tlačítkem na soubor a zvol Delete.

***Terminál:***
```bash
git rm název_souboru
git commit -m "Odstranění souboru"
```
# 🚀 Tipy pro Efektivní Používání Git ve VS Code

## **Rozšíření GitLens:**
GitLens zvyšuje funkcionalitu Git ve VS Code, nabízí lepší historii, anotace a další.

**Příkazová Paleta:**
Otevři pomocí Ctrl + Shift + P a zadej Git příkazy pro rychlý přístup (např. Git: Commit, Git: Push).

**Integrovaný Terminál:**
Otevři terminál přímo ve VS Code pomocí Ctrl + ` pro rychlé spouštění Git příkazů.

**Klávesové Zkratky:**
Nauč se základní zkratky pro rychlejší práci:
- Ctrl + Shift + G – Otevření Source Control panelu.
- Ctrl + Enter – Commit změn.
- Ctrl + P – Rychlé hledání souborů a příkazů.

**Automatické Dokončování Příkazů:**
V terminálu ve VS Code máš přístup k automatickému dokončování příkazů, což urychluje práci.

# 📚 Další Zdroje
## **Oficiální Dokumentace Git:**
Git Documentation

***Dokumentace VS Code:***
Using Git in VS Code

***Rozšíření pro VS Code:**
GitHub Pull Requests and Issues
GitLens
