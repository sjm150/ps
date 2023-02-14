use std::io::{self, Read};
use std::collections::HashSet;

fn main() {
    let mut buf = String::with_capacity(4000050);
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let num_a: usize = input.next().unwrap().parse().unwrap();
    let num_b: usize = input.next().unwrap().parse().unwrap();

    let mut set_a = HashSet::<usize>::with_capacity(200000);
    for _i in 0..num_a {
        set_a.insert(input.next().unwrap().parse().unwrap());
    }

    let mut num_dup = 0;
    for _i in 0..num_b {
        if set_a.contains(&input.next().unwrap().parse::<usize>().unwrap()) {
            num_dup += 1;
        }
    }

    println!("{}", num_a + num_b - 2 * num_dup);
}
