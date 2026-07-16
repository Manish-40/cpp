class User{
    constructor(username){
        this.username=username;
    }
    logMe(){
        console.log(`USERNAME IS ${this.username}`);
    }
}

class Teacher extends User{
    constructor(username,email,password){
        super(username)
        this.email=email;
        this.password=password;
    }


    addCourse(){
        console.log(`New course was added by ${this.username}`);
    }
}

const chai=new Teacher("chai","chai@teacher.com","123");
chai.addCourse();
const masalaChai=new User("masalaChai");
masalaChai.logMe()
chai.logMe()

console.log(chai instanceof User);
