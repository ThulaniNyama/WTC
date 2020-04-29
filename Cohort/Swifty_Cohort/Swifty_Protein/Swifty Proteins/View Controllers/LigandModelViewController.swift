//
//  LigandModelViewController.swift
//  Swifty Proteins
//
//  Created by Thulani Nyama on 2019/11/22.
//  Copyright © 2019 tnyama. All rights reserved.
//

import UIKit
import SceneKit

class LigandModelViewController: UIViewController {

    //scene kit properties
    @IBOutlet weak var sceneKitView: SCNView!
    var gameScene : SCNScene!
    var cameraNode : SCNNode!
    var targetCreationTime : TimeInterval = 0
    
    @IBOutlet weak var selectedElementLabel: UILabel!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    var ligandName : String = ""
    var ListOfAtoms : [Atom] = []
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.title = "\(self.ligandName)"
        self.activityIndicator.hidesWhenStopped = true
        self.selectedElementLabel.isHidden = true
        DispatchQueue.main.async {
            self.activityIndicator.startAnimating()
        }
        
        //call scene kit init functions
        self.initView()
        self.initScene()
        self.initCamera()
        
        self.getLigandData(ligandName: self.ligandName, with: { (data) -> (Void) in
            
            self.extractDataAndCreateAtoms(data: data)
            for atomium in self.ListOfAtoms
            {
                self.createAtom(atom: atomium)
                for connector in atomium.Connections
                {
                    let source = SCNVector3(atomium.xPos, atomium.yPos, atomium.zPos)
                    let destinationAtom = self.ListOfAtoms[connector - 1] as Atom
                    let destination = SCNVector3(destinationAtom.xPos, destinationAtom.yPos, destinationAtom.zPos)
                    let connection:SCNNode = CylinderLine(parent: self.gameScene.rootNode, v1: source, v2: destination, radius: 0.1, radSegmentCount: 10, color: .gray)
                    self.gameScene.rootNode.addChildNode(connection)
                }
                DispatchQueue.main.async {
                    self.selectedElementLabel.isHidden = false
                    self.activityIndicator.stopAnimating()
                }
            }
        }, with: { (error) -> (Void) in
            print(error.localizedDescription)
            let alert = self.createAlert(title: "ligand error", message: "failed to load ligand data")
            self.present(alert, animated: true, completion: nil)
        })
    }
    
    override func willMove(toParentViewController parent: UIViewController?) {
        
    }
    
    @IBAction func ShareButtonClick(_ sender: UIButton)
    {
        let image = self.sceneKitView.snapshot()
        let activityController = UIActivityViewController(activityItems: [image], applicationActivities: nil)
        present(activityController, animated: true, completion: nil)
    }
    
    func getColor(AtomSymbol : String) -> UIColor
    {
        if (AtomSymbol == "H")
        {
            return UIColor.white
        }
        else if (AtomSymbol == "C")
        {
            return UIColor.black
        }
        else if (AtomSymbol == "N")
        {
            return UIColor.init(red: 0.000, green: 0.000, blue: 0.545, alpha: 1)
        }
        else if (AtomSymbol == "O")
        {
            return UIColor.red
        }
        else if (AtomSymbol == "F" || AtomSymbol == "Cl")
        {
            return UIColor.green
        }
        else if (AtomSymbol == "Br")
        {
            return UIColor.init(red: 0.624, green: 0.000, blue: 0.545, alpha: 1)
        }
        else if (AtomSymbol == "I")
        {
            return UIColor.init(red: 0.396, green: 0.094, blue: 0.722, alpha: 1)
        }
        else if (AtomSymbol == "He" || AtomSymbol == "Ne" || AtomSymbol == "Ar" || AtomSymbol == "Xe" || AtomSymbol == "Kr")
        {
            return UIColor.cyan
        }
        else if (AtomSymbol == "P")
        {
            return UIColor.orange
        }
        else if (AtomSymbol == "S")
        {
            return UIColor.yellow
        }
        else if (AtomSymbol == "B")
        {
            return UIColor.init(red: 1.000, green: 0.855, blue: 0.725, alpha: 1)
        }
        else if (AtomSymbol == "Li" || AtomSymbol == "Na" || AtomSymbol == "K" || AtomSymbol == "Rb" || AtomSymbol == "Cs" || AtomSymbol == "Fr")
        {
            return UIColor.init(red: 0.463, green: 0.145, blue: 0.984, alpha: 1)
        }
        else if (AtomSymbol == "Be" || AtomSymbol == "Mg" || AtomSymbol == "Ca" || AtomSymbol == "Sr" || AtomSymbol == "Ba" || AtomSymbol == "Ra")
        {
            return UIColor.init(red: 0.055, green: 0.459, blue: 0.059, alpha: 1)
        }
        else if (AtomSymbol == "Ti")
        {
            return UIColor.gray
        }
        else if (AtomSymbol == "Fe")
        {
            return UIColor.init(red: 0.859, green: 0.463, blue: 0.122, alpha: 1)
        }
        return UIColor.init(red: 0.863, green: 0.482, blue: 0.988, alpha: 1)
    }
    
    func getLigandData(ligandName : String, with success : @escaping (Data) -> (Void), with erroring : @escaping (Error) -> (Void))
    {
        let url = URL(string:"https://files.rcsb.org/ligands/view/\(self.ligandName)_ideal.pdb")
        let request = NSMutableURLRequest(url: url!)
        activityIndicator.startAnimating()
        let task = URLSession.shared.dataTask(with: request as URLRequest){
            (data, response, error) in
            if let err = error{
                erroring(err)
            }
            else if (data != nil){
                success(data!)
            }
        }
        task.resume()
        activityIndicator.stopAnimating()
    }
    
    func extractDataAndCreateAtoms(data : Data)
    {
        let decodedData = String(data: data, encoding: .utf8)!
        let splitData = decodedData.split(separator: "\n")
        for line in splitData
        {
           let atomDetails = line.split(separator: " ")
           if atomDetails[0].uppercased() == "ATOM"
           {
                let atom = Atom(_id: Int(atomDetails[1])!, _symbol: String(atomDetails[11]), _xPos: Double(atomDetails[6])!, _yPos: Double(atomDetails[7])!, _zPos: Double(atomDetails[8])!)
                self.ListOfAtoms.append(atom)
           }
           else if atomDetails[0].uppercased() == "CONECT"
           {
                //this part will add all the connections that an atom has to other atoms
                for atom in self.ListOfAtoms
                {
                    if atom.id == Int(atomDetails[1])
                    {
                        let index : Int = atomDetails.count - 2
                        var index2 : Int = atomDetails.count - index

                        while index2 < atomDetails.count
                        {
                            atom.setConnections(connection: Int(atomDetails[index2])!)
                            index2 += 1
                        }
                    }
                }
           }
           else if atomDetails[0].uppercased() == "END"
           {}
           else
           {
            DispatchQueue.main.async {
                let alert = self.createAlert(title: "ligand error", message: "failed to load ligand from the data bank")
                self.present(alert, animated: true, completion: nil)
            }
            return ;
           }
        }
    }
    
    //scene kit functions
    func initView () {
        self.sceneKitView.allowsCameraControl = true
        self.sceneKitView.autoenablesDefaultLighting = true
    }
    
    func initScene ()
    {
        self.gameScene = SCNScene()
        self.sceneKitView.scene = self.gameScene
        self.sceneKitView.isPlaying = true
    }
    
    func initCamera()
    {
        self.cameraNode = SCNNode()
        self.cameraNode.camera = SCNCamera()
        self.cameraNode.position = SCNVector3(x : 0, y : 0, z :20)
        self.gameScene.rootNode.addChildNode(self.cameraNode)
    }
    
    func createAtom(atom : Atom)
    {
        let geometry : SCNGeometry = SCNSphere(radius: 0.35)
        geometry.materials.first?.diffuse.contents = self.getColor(AtomSymbol: atom.Symbol)
        
        let geometryNode = SCNNode(geometry: geometry)
        geometryNode.name = atom.Symbol
        geometryNode.position = SCNVector3(x : Float(atom.xPos), y : Float(atom.yPos), z : Float(atom.zPos))
        
        self.gameScene.rootNode.addChildNode(geometryNode)
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        let touch = touches.first!
        
        let location =  touch.location(in: self.sceneKitView)
        
        let hitList = self.sceneKitView.hitTest(location, options: nil)
        
        if let hitObject = hitList.first {
            let node = hitObject.node
            
            self.selectedElementLabel.text = "Selected Element : \(String(node.name ?? "No Name"))"
        }
    }
    
    func createAlert(title : String, message : String) -> UIAlertController{
        let alert = UIAlertController(title: title, message: message, preferredStyle: UIAlertControllerStyle.alert)
        alert.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default, handler: { (action) in
            alert.dismiss(animated: true, completion: nil)
        }))
        return alert
    }
}

