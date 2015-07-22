//
//  InterfaceController.swift
//  watchOS_test WatchKit Extension
//
//  Created by Fernando Romiti on 7/13/15.
//  Copyright © 2015 Fernando Romiti. All rights reserved.
//

import WatchKit
import Foundation


class InterfaceController: WKInterfaceController {

    var brain = TestBrain()
    var correctWord = String() {
        didSet {
            self.displayedWord = brain.mixLettersInWord(self.correctWord)
            self.word.setText(self.displayedWord)
        }
    }
    var displayedWord = String()
    var timer = NSTimer()
    var pointsCount = 0
    var lives = 3
    var dificultyLavel = 0.0 {
        didSet {
            self.setTimer()
        }
    }
    
    @IBOutlet var word: WKInterfaceLabel!
    @IBOutlet var heart3: WKInterfaceImage!
    @IBOutlet var heart2: WKInterfaceImage!
    @IBOutlet var heart1: WKInterfaceImage!
    @IBOutlet var points: WKInterfaceLabel!
    @IBOutlet var dificulty: WKInterfaceSlider!
    
    @IBAction func checkWord() {
        NSLog("check")
        if self.correctWord == self.displayedWord {
            self.pointsCount += 1
            self.points.setText("Points: ".stringByAppendingString(String(self.pointsCount)))
            self.correctWord = brain.getWord()
        }
        else {
            self.updateLives()
        }
    }
    
    @IBAction func updateDificulty(value: Float) {
        if self.dificultyLavel != Double(value) {
            NSLog("dificulty was: %f and will be set to: %f", self.dificultyLavel, value)
            self.dificultyLavel = Double(value)
        }
        NSLog("Nothing to update")
    }
    
    override func awakeWithContext(context: AnyObject?) {
        super.awakeWithContext(context)
        
        // Configure interface objects here.
        self.correctWord = brain.getWord()
        self.update()
    }
    
    func update() {
        if self.correctWord == self.displayedWord {
            self.updateLives()
        }
        else {
            self.displayedWord = brain.mixLettersInWord(self.correctWord)
            self.word.setText(self.displayedWord)
            self.setTimer()
        }
    }
    
    func updateLives() {
        NSLog("lives: ", self.lives)
        self.lives--
        switch self.lives {
        case 3: NSLog("lives: %i", self.lives)
        case 2: self.heart1.setImage(UIImage(named: "heart"))
        case 1: self.heart2.setImage(UIImage(named: "heart"))
        case 0:
            self.heart3.setImage(UIImage(named: "heart"))
            self.gameOver()
        default: NSLog("Error in lives!!!")
        }
    }
    
    func gameOver() {
        self.timer.invalidate()
        self.popController()
    }
    
    func setTimer() {
        self.timer.invalidate()
        self.timer = NSTimer.scheduledTimerWithTimeInterval(3.5 - self.dificultyLavel, target: self, selector: Selector("update"), userInfo: nil, repeats: true)
    }
    

    override func willActivate() {
        // This method is called when watch view controller is about to be visible to user
        super.willActivate()
        self.timer = NSTimer.scheduledTimerWithTimeInterval(5.0, target: self, selector: Selector("update"), userInfo: nil, repeats: true)
    }

    override func didDeactivate() {
        // This method is called when watch view controller is no longer visible
        super.didDeactivate()
    }

}
