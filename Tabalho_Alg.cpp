#include<iostream>
#include<stdio.h>
#include<locale.h>
using namespace std;

struct produto
{
    string nome;
    float precoCompra;
    float precoVenda;
};

struct vendedor
{
    string nome;
    int idade;
    bool sexo;
};

struct estoque
{
    //produto prod[1000];
    int quant_desejada[1000];
    int quant_atual[1000];

};
struct cliente
{
    string Nome,endereco,idade,cpf,telefone,estado,cep;

};
struct venda
{
    string Data ;
    float preco_total;
    int quantVENDIDA[10000];
};





int main ()
{
    setlocale (LC_ALL, "");
    //float precompra,prevenda;
    int num_prod, num_vendedores, num_clientes, op;
    int maior, maior2, maior3, p1, p2, p3;

///produto
    cin>>num_prod;
    produto produt[1000];
    for(int i=0; i<num_prod; i++)
    {
        fflush(stdin);
        getline(cin,produt[i].nome);
        cin>>produt[i].precoCompra;
        cin>>produt[i].precoVenda;
    }
///vendedor
    vendedor srs[10000];
    cin>>num_vendedores;
    for (int i=0; i<num_vendedores; i++)
    {
        fflush(stdin);
        getline(cin,srs[i].nome);
        cin>>srs[i].idade;
        //cout 0 homem, 1 mulher
        cin>>srs[i].sexo;
    }
///estoque

    estoque lispro;
    for (int i=0; i<num_prod; i++)
    {
        cin>>lispro.quant_desejada[i];
        cin>>lispro.quant_atual[i];
    }



///venda
    venda produtos;
    getline (cin,produtos.Data);
    cin>>produtos.preco_total;

    for (int i=0; i<num_prod; i++)
    {
        produtos.quantVENDIDA[i];
    }

///cliente
    cliente clientes[10000];
    cin>>num_clientes;
    for (int i=0; i<num_clientes; i++)
    {
        fflush (stdin);
        getline (cin,clientes[i].Nome);
        fflush (stdin);
        getline (cin,clientes[i].endereco);
        fflush (stdin);
        getline (cin,clientes[i].idade);
        fflush (stdin);
        getline (cin,clientes[i].cpf);
        fflush (stdin);
        getline (cin,clientes[i].telefone);
        fflush (stdin);
        getline (cin,clientes[i].estado);
        fflush (stdin);
        getline (cin,clientes[i].cep);
    }

    ///MENU
    cout<< "----------------------------------------------------"<<endl;
    cout<< "1 -- EXIBIR ESTOQUE"<<endl;
    cout<< "2 -- EXIBIR PRODUTOS"<<endl;
    cout<< "3 -- EXIBIR VENDAS"<<endl;
    cout<< "4 -- EXIBIR UNIDADES"<<endl;
    cout<< "5 -- EXIBIR CUSTO ATUAL NO ESTOQUE"<<endl;
    cout<< "6 -- EXIBIR CUSTO DO ESTOQUE DESEJÁVEL"<<endl;
    cout<< "7 -- EXIBIR LUCRO TOTAL DAS VENDAS"<<endl;
    cout<< "8 -- EXIBIR RANKING VENDEDOR"<<endl;
    cout<< "9 -- EXIBIR PRODUTOS MAIS VENDIDOS"<<endl;

    cout<< "----------------------------------------------------"<<endl;
    cin>>op;

    switch (op)
    {

    case 1:
        for (int i=0; i<num_prod; i++)
        {
            cout<< "Nome: "<<produt[i].nome<<endl;
            cout<< "Preço de Compra: "<<produt[i].precoCompra<<endl;
            cout<< "Preço de Venda: "<<produt[i].precoVenda<<endl;
            cout<< "Quantidade Desejada: "<<lispro.quant_desejada[i]<<endl;
            cout<< "Quantidade Atual: "<<lispro.quant_atual[i]<<endl;
        }
        break;
    case 2:
        for (int i=0; i<num_prod; i++)
        {
            cout<< "Nome: "<<produt[i].nome<<endl;
            cout<< "Preço de Compra: "<<produt[i].precoCompra<<endl;
            cout<< "Preço de Venda: "<<produt[i].precoVenda<<endl;
        }
        break;
    case 3:
        cout<< "Data: "<<produtos.Data<<endl;
        cout<< "Preço Total: "<<produtos.preco_total<<endl;
        for (int i=0; i<num_prod; i++)
        {
            cout<< "Nome: "<<produt[i].nome<<endl;
            cout<<produtos.quantVENDIDA[i]<<endl;
        }
        break;
    case 4:
        for (int i=0; i<num_prod; i++)
        {
            cout<< "Nome: "<<produt[i].nome<<endl;
            cout<< "Unidades: "<<lispro.quant_atual[i]<<endl;
        }
        break;
    case 5:
        for (int i=0; i<num_prod; i++)
        {
            cout<< ""<<produt[i].nome<<endl;
            cout<< ""<<lispro.quant_atual[i]*produt[i].precoCompra<<endl;
        }
        break;
    case 6:
        for (int i=0; i<num_prod; i++)
        {
            cout<< ""<<produt[i].nome<<endl;
            cout<< ""<<lispro.quant_desejada[i]*produt[i].precoCompra<<endl;
        }
        break;
    case 7:
        for (int i=0; i<num_prod; i++)
        {
            cout<< "Nome: "<<produt[i].nome<<endl;
            cout<< "Lucro: "<<(produt[i].precoVenda*produtos.quantVENDIDA[i])-(produtos.quantVENDIDA[i]*produt[i].precoCompra)<<endl;
        }
        break;
    case 8:
        for (int i=0; i<num_vendedores; i++)
        {
            cout<< "Nome: "<<srs[i].nome<<endl;
            cout<< "Idade: "<<srs[i].idade;
            cout<< "Sexo: ";
            if (srs[i].sexo==0)
            {
                cout<<"Masculino"<<endl;
            }
            else if (srs[i].sexo==1)
            {
                cout<< "Feminino"<<endl;
            }

        }

        break;

    case 9: //Top 3 Mais Vendidos
        for (int i=0; i<num_prod; i++) {
    if (i==0)
    maior=produtos.quantVENDIDA[i];
    else
    {
        if (produtos.quantVENDIDA[i]>maior)
        {
            maior2=maior;
            maior=produtos.quantVENDIDA[i];
            p2=i;
            p1=i;
        }
        if (produtos.quantVENDIDA[i]>maior2)
        {
            maior3=maior2;
            maior2=produtos.quantVENDIDA[i];
            p2=i;
        }
        if (produtos.quantVENDIDA[i]>maior3)
        {
            maior3=produtos.quantVENDIDA[i];
            p3=i;
        }
    }
    }
    cout<< "1º Mais Vendido: "<<endl;
    cout<< "\n Nome: "<<produt[p1].nome<<endl;
    cout<< "\n Quantidade Vendida: "<<produtos.quantVENDIDA[p1]<<endl;
    cout<< "\n\n"<<endl;

    cout<< "2º Mais Vendido: "<<endl;
    cout<< "\n Nome: "<<produt[p2].nome<<endl;
    cout<< "\n Quantidade Vendida: "<<produtos.quantVENDIDA[p2]<<endl;
    cout<< "\n\n"<<endl;

    cout<< "1º Mais Vendido: "<<endl;
    cout<< "\n Nome: "<<produt[p3].nome<<endl;
    cout<< "\n Quantidade Vendida: "<<produtos.quantVENDIDA[p3]<<endl;
    cout<< "\n\n"<<endl;
        break;
    }
    return 0;
}

