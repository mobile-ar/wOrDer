//
//  UnlockInterfaceController.swift
//  wOrDer
//
//  Created by Fernando Romiti on 7/17/15.
//  Copyright © 2015 Fernando Romiti. All rights reserved.
//

import WatchKit
import Foundation


class UnlockInterfaceController: WKInterfaceController {

    
    @IBOutlet var success: WKInterfaceLabel!
    @IBOutlet var fails: WKInterfaceLabel!
    
    @IBOutlet var picker1: WKInterfacePicker!
    @IBOutlet var picker2: WKInterfacePicker!
    @IBOutlet var picker3: WKInterfacePicker!
    
    var value1 = 0
    var value2 = 0
    var value3 = 0
    
    var ok = 0
    var bad = 0

    @IBAction func picker1Action(value: Int) {
        self.value1 = value
    }
    
    @IBAction func picker2Action(value: Int) {
        self.value2 = value
    }
    
    @IBAction func picker3Action(value: Int) {
        self.value3 = value
    }
    
    
    override func awakeWithContext(context: AnyObject?) {
        super.awakeWithContext(context)
        
        // Configure interface objects here.

        var items = [WKPickerItem]()
        for ctr in 0...9 {
            let item = WKPickerItem()
            item.title = String(ctr)
            item.caption = String(ctr)
            items.append(item)
            NSLog("item %@", item)
        }
        
        picker1.setItems(items)
        picker2.setItems(items)
        picker3.setItems(items)
    }

    override func willActivate() {
        // This method is called when watch view controller is about to be visible to user
        super.willActivate()
    }

    override func didDeactivate() {
        // This method is called when watch view controller is no longer visible
        super.didDeactivate()
    }
    
    @IBAction func checkCode() {
        NSLog("val1: %i, val2: %i, val3: %i", self.value1, self.value2, self.value3)
        if self.value1 == 9 && self.value2 == 9 && self.value3 == 9 {
            self.ok++
            self.success.setText(String(self.ok))
        }
        else {
            self.bad++
            self.fails.setText(String(self.bad))
        }
    }
    
}
