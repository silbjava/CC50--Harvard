from cs50 import get_int

def main():
    height = get_int("Digite a altura da pirâmide:\n")

    while height < 1 or height > 8:
        print("Tamanho inválido! Por favor, insira um número entre 1 e 8.\n")
        height = get_int("Digite a altura da pirâmide:\n")

    for i in range(1, height + 1):
        print(" " * (height - i), end="")
        print("#" * i, end="  ")
        print("#" * i)

if __name__ == "__main__":
    main()
