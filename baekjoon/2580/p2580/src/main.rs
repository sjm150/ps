use std::io::{self, Read};

struct Group {
    exist: [bool; 9],
    size: u32,
}

impl Copy for Group {}

impl Clone for Group {
    fn clone(&self) -> Group {
        Group {
            exist: self.exist,
            size: self.size,
        }
    }
}

impl Group {
    fn new() -> Group {
        Group {
            exist: [false; 9],
            size: 0,
        }
    }

    fn insert(&mut self, number: usize) {
        self.exist[number - 1] = true;
        self.size += 1;
    }

    fn delete(&mut self, number: usize) {
        self.exist[number - 1] = false;
        self.size -= 1;
    }
}

fn candidates(rows: &mut [Group], cols: &mut [Group], cels: &mut [Group]) -> impl Iterator {

}

fn fill_one(rows: &mut [Group], cols: &mut [Group], cels: &mut [Group]) {
    for row in rows {
        if row.size == 8 {
            
        }
    }
}

fn main() {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut numbers = buf.split_ascii_whitespace();

    let mut rows = [Group::new(); 9];
    let mut cols = [Group::new(); 9];
    let mut cels = [Group::new(); 9];

    for i in 0..9 {
        for j in 0..9 {
            let number: usize = numbers.next().unwrap().parse().unwrap();
            if number == 0 {
                continue;
            }

            rows[i].insert(number);
            cols[j].insert(number);
            cels[3 * i + j].insert(number);
        }
    }

}
