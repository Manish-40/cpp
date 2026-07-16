const marvel_heros=["thor","ironman","spiderman"]
const dc_heros=["superman","flash","batman"]

// marvel_heros.push(dc_heros)

// console.log(marvel_heros);
// console.log(marvel_heros[3][1]);

// const all_heros=marvel_heros.concat(dc_heros); // conact 2 or 3 arrays ne combine kare che ne navu aaray return kare che without modifying an existing arrray

// console.log(all_heros);

const all_newheros=[...marvel_heros,...dc_heros] // aji add kari sakiye , nakhi ne 
// aa all_newheros spred thai gaya aetle kach no glas fekyo to tukda thia jase
// ... no matlab che marvel_heros nu array e single elemnet thai gaya che have e array nathi
console.log(all_newheros); //spred out values madse

const another_array=[1,2,3,[4,5,6],7,[6,7,[4,5]]];

const real_another_array=another_array.flat(Infinity);
// flat subarrays ne 1 nava array ma return kare che
// infinity aetle aema aapde ketla depth tak karvu che apada ma shayad 3 depth che to ganva kon bese to infinity nakhi do

console.log(real_another_array);

console.log(Array.isArray("Hitesh"))
console.log(Array.from("Hitesh"))
console.log(Array.from({name:"hitsh"})) // interesting aama kevu pade key nu array banavo ke value nu

let score1=100;
let score2=200;
let score3=300;

console.log(Array.of(score1,score2,score3)); // array banavse variable nu


