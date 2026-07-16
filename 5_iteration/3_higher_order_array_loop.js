// for of

["","",""]
[{},{},{}]

const array=[1,2,3,4,5]
for (const element of array) {
    console.log(element);   
}

const greetings="Hello world";
for (const greet of greetings) {
    console.log(`Each char is ${greet}`);
    
}

// Map

const map=new Map()
map.set('IN','India')
map.set('US','United States of America')
map.set('FR','France');
map.set('IN','India')
console.log(map);
// for in loop na lage map ma
for (const [key,value] of map) {
    console.log(key, ':-', value);
}

const myObject={
    'game1':'NFS',
    'game2':'spiderman'
}
for (const [key,value] of myObject) { // error
    console.log(key, ':-', value);
}
