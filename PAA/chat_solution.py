def lcs(str1, str2):
    # Comprimentos das duas strings
    m, n = len(str1), len(str2)
    
    # Tabela para armazenar resultados de subproblemas
    dp = [[0] * (n+1) for _ in range(m+1)]
    
    # Para armazenar o comprimento da LCS
    result = 0
    
    # Final da LCS na string str1
    end_index = 0
    
    # Preenchendo dp[][]
    for i in range(1, m+1):
        for j in range(1, n+1):
            if str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
                # Se o comprimento atual for maior que o result,
                # atualizamos o result e end_index
                if dp[i][j] > result:
                    result = dp[i][j]
                    end_index = i
            else:
                dp[i][j] = 0
                
    # A maior substring comum será de tamanho 'result'
    # e terminará no índice 'end_index' em str1.
    return str1[end_index - result: end_index]

# Testando o algoritmo
str1 = "BIA"
str2 = "BEA"
print(lcs(str1, str2))  # Deve imprimir 'BABC'
