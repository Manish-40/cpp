const mynums=[1,2,3,4]

let mytotal=mynums.reduce(function(acc,cval){
    console.log(`acc: ${acc} and cval: ${cval}`);
    
    return acc+cval;
},0)

console.log(mytotal);
let mytotal1=mynums.reduce((acc,cval)=>(acc+cval),0)


const shoppingcart=[
    {
        itemname:"jscourse",
        price:2999
    },
    {
        itemname:"python",
        price:2999
    },
    {
        itemname:"mobile dev course",
        price:3999
    },
    {
        itemname:"data science course",
        price:12999
    }
]
let shop=shoppingcart.reduce((acc,item)=>item.price+acc,0)

console.log(shop);
