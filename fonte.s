FUNÇÃO:
    funcao2() =
        ação: 
            retorne funcao(3, 4)

    funcao(valor arg3 : inteiro, valor arg4: inteiro) : inteiro = 
        local:
            a : inteiro := arg3

        ação:
            imprimei(a);
            a := 10 + 2 * 2;
            imprimei(a)

AçÃo:
    retorne funcao2()