use std::io;
use std::collections::HashSet;

fn main() {
    let mut _n = String::new();
    let mut cards = HashSet::new();

    io::stdin().read_line(&mut _n).expect("read_line");

    let mut args = String::new();
    io::stdin().read_line(&mut args).expect("read_line");
    let args: HashSet<i32> = args.split_whitespace().map(|x| x.parse().expect("parse")).into_iter().collect::<HashSet<_>>();

    for card in args {
        cards.insert(card);
    }

    io::stdin().read_line(&mut _n).expect("read_line");

    let mut args = String::new();
    io::stdin().read_line(&mut args).expect("read_line");
    let args = args.split_whitespace();

    for card in args {
        if cards.contains(&card.parse::<i32>().expect("parse")) {
            print!("1 ");
        } else {
            print!("0 ");
        }
    }
    println!();
}
