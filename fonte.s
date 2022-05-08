FUNÇÃO:
    procedimento1(valor arg45: inteiro, valor arg46 : inteiro) =
        local:
            b : inteiro := 2
        ação:
            arg45 := funcao1(3+1, 4)

    funcao1(valor arg3 : inteiro, valor arg4: inteiro) : inteiro =
        local:
            a : inteiro := 2

        ação: 
            imprimei(funcao5(2));
            a := 2;
            imprimei(a + 3 - 3);
            retorne 2

    funcao5(valor argFuncao5 : inteiro) : inteiro =
        local:
            b : inteiro := 1
        ação:
            retorne 5

AçÃo:
    procedimento1(1, 2+1);
    retorne 0
