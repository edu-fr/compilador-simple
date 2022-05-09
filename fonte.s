FUNÇÃO:
    FUNCAO(valor arg45: inteiro, valor arg46 : inteiro) : inteiro =
    ação:
        imprimei(25);
        retorne funcao5(arg45)

    /* funcao1(valor arg3 : inteiro, valor arg4: inteiro) : inteiro =
        local:
            a : inteiro := 2

        ação: 
            imprimei(a);
            a := 200;
            retorne 2*/

    funcao5(valor argFuncao5 : inteiro) : inteiro =
        local:
            a : inteiro := 2

        ação:
            imprimei(argFuncao5);
            argFuncao5 := 250;
            imprimei(argFuncao5);
            retorne argFuncao5

AçÃo:
    imprimei(10);
    imprimei(FUNCAO(10, 20));
    retorne 0
