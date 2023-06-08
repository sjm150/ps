use std::io::{self, Read};

fn main() {
    let mut buf = String::with_capacity(100000);
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let t: u32 = input.next().unwrap().parse().unwrap();

    for _i in 0..t {
        let x_1: i32 = input.next().unwrap().parse().unwrap();
        let y_1: i32 = input.next().unwrap().parse().unwrap();
        let x_2: i32 = input.next().unwrap().parse().unwrap();
        let y_2: i32 = input.next().unwrap().parse().unwrap();

        let mut num = 0;

        let n: u32 = input.next().unwrap().parse().unwrap();
        for _j in 0..n {
            let c_x: i32 = input.next().unwrap().parse().unwrap();
            let c_y: i32 = input.next().unwrap().parse().unwrap();
            let r: i32 = input.next().unwrap().parse().unwrap();

            if in_circle(x_1, y_1, c_x, c_y, r) != in_circle(x_2, y_2, c_x, c_y, r) {
                num += 1;
            }
        }

        println!("{}", num);
    }
}

fn in_circle(x: i32, y: i32, c_x: i32, c_y: i32, r: i32) -> bool {
    let x_diff = c_x - x;
    let y_diff = c_y - y;
    x_diff * x_diff + y_diff * y_diff < r * r
}
