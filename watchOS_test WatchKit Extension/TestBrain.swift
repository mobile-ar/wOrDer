//
//  TestBrain.swift
//  watchOS_test
//
//  Created by Fernando Romiti on 7/13/15.
//  Copyright © 2015 Fernando Romiti. All rights reserved.
//

import Foundation


class TestBrain: NSObject {
    
    //get something better here from a words database or something
    var words = ["test", "car", "dog", "bit", "trip", "rope", "sky", "text", "type", "watch", "apple", "red", "iron", "man"]
    
    //get a correct word from the "database" :P
    func getWord() -> String {
        let index = randomInt(0, max: (words.count - 1))
        NSLog(String(index))
        return words[index]
    }
    
    //get random number betwen min and max values
    func randomInt(min: Int, max:Int) -> Int {
        return min + Int(arc4random_uniform(UInt32(max - min + 1)))
    }
    
    //shuffle letters for a given word
    func mixLettersInWord(word: String) -> String {
        var returnWord = String()
        if randomInt(0, max: 3) != 0 {
            var elements = Array(word.characters)
            for index in 0..<elements.count {
                swap(&elements[index], &elements[ Int(arc4random_uniform(UInt32(elements.count))) ])
            }
            returnWord = String(elements)
        }
        else {
            returnWord = word
        }
        
        return returnWord
    }
    
    
}