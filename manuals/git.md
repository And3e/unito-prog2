# **git** - GitLab

## Creazione nuovo progetto

### `1` Inizializzazione progetto (repository)
```bash
git init
```

### `2` SSH keygen

```bash
ssh-keygen -t rsa
# 2. Immettere DIR di salvataggio desiderata
# 3. Mettere password (se desiderata)
```

### `3` Aggiungere la chiave SSH nelle configurazioni

```bash
cd ssh # cd → DIR ssh
more id_ed25519.pub
# 3. Copiare il contenuto della chiave e incollarlo su git
```

### `4` Autenticare la chiave

```bash
ssh git@gitlab.com
# 2. → "yes"
```

### `5` Configurazione utente

```bash
git config --global user.email "<mail>"
git config --global user.name "<nome>"
```

### `6` Clonare il progetto

```bash
git clone https://gitlab.com/<account>/<nome_progetto>.git
```

## `7` Push aggiornamenti

```bash
cd <dir_progetto>
git add .
git commit -m "<Messaggio>"
git push
```

<hr>

## Branch

```bash
git checkout -b <Nomebranch> # creare branch

git branch -d <Nomebranch> # eliminare branch

git branch -D <Nomebranch> # eliminare branch anche se non unito (merge)

git checkout <Nomebranch> # spostarsi di branch

git branch # vedere tutti i branch presenti

git push --set-upstream origin <Nomebranch> # push di un nuovo branch

git push origin --delete <Nomebranch> # eliminare branch in remoto
```
