class User{
    constructor(email,password){
        this.email=email;
        this.password=password;
    }
    get email(){
        return this._email.toUpperCase()
    }
    set email(value){
        this._email=value;
    }
    get password(){
        return `${this._password}hitesh` //set ma original value stored thase pan get ma aapde je user ne batavu hoy e batavi sakiye
    }

    set password(value){
        this._password=value
    }
}
const hitesh=new User("h@hitesh.ai","abc")
console.log(hitesh.email);
console.log(hitesh.password);
