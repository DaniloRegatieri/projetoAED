# projetoAED
Projeto de AED - Uno

# 1. Guia rápido de uso de branches
## i) A branch principal é a main, e cada participante deve trabalhar na sua própria branch. Para entrar na sua branch, digite:
     git checkout nome (danilo/bruno/heitor)

## ii) Antes de começar a editar o código principal, sincronize sua branch com a main para evitar conflitos:
    git checkout main
    git pull origin main          # baixa as atualizações da main
    git checkout nome (danilo/bruno/heitor)
    git merge main                # mescla as mudanças da main na sua branch
    
## iii) Faça commits e envie suas mudanças. Quando terminar uma parte do trabalho e quiser colocar no main, faça:
    git add .
    git commit -m "Descreva brevemente o que foi feito"
    git push origin nome (danilo/bruno/heitor)

## iv) Faça o merge (Pull Request). Quando seu código estiver pronto para entrar na main:

***Nunca faça merge direto sem aprovação, a menos que seja combinado com o grupo***

    1. Vá até o repositório no GitHub.

    2. Clique em “Compare & pull request”.

    3. Descreva o que foi feito e peça revisão.

    4. Após revisão e aprovação, o merge será feito na main.


### OBS: se você tiver alterado algo na sua branch e der: *pull origin main* + *merge main* você **NÂO** perderá seus arquivos, mas não tenho certeza.
