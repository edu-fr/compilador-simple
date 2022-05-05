FUNÇÃO:
    funcao(valor arg3 : inteiro, valor arg4: inteiro) : inteiro = 
        local:
            a : inteiro := arg3

        ação:
            imprimei(a);
            a := 6 + 2 * 2;
            imprimei(a)

    main() : inteiro =
        ação:
            retorne funcao(109, 2)

AçÃo:
       retorne 91