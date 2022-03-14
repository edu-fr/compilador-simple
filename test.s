tipo: 
    tipoNovo = tipoAntigo
    tipoVelho = newerType
    tipoRegistro = { regCampo1: tipoNovo, regCampo2: tipoVelho }

global: 
    varglob: tipoNovo := NULO 

funÇão: 
    fiuncao (rEf param1: tipoVelho, vaLor paRam2: inteIRO ) : tipoVelho = 
        local:  
            novaLocal: tipoNovo := NULO 
            novaNovaLocal: tipoVelho := NULO
            localRegistro: tipoRegistro := { regCampo1 = 1 + 1 , regCampo2 = 10}
        ação: 
            ident := nulo;
            ident2 := nulo