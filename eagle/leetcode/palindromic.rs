fn is_palindrome(x:i32)->bool{
    if x == 0 {
        return true;
    }

    if x < 0 || (x % 10 == 0){
        return false;
    }

    let mut ori = x;
    let mut rev = 0;
    
    while rev < ori {
        rev = rev * 10 + ori % 10;
        ori = ori/10;
    }

    return rev == ori || rev/10 == ori; 
}

fn main() {
    println!("{}", is_palindrome(0));
    println!("{}", is_palindrome(10));
    println!("{}", is_palindrome(121));
    println!("{}", is_palindrome(1221));
    println!("{}", is_palindrome(1231));
}