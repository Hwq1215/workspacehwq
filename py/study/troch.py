from dataclasses import dataclass
import torch as th 
import numpy as np
from torch.utils.data import Dataset 

print(th.cuda.is_available())
print(th.cuda.device_count())

class bee(Dataset):
    def __init__(self):
        self.file_path = "./data/data.txt"
        self.file_path = ""
        self.
    def __getitem__(self, content):
        
    def __len__(self):


class face_dataset(data.Dataset):
    def __init__(self):
        self.file_path = './data/faces/'
        f=open("final_train_tag_dict.txt","r")
        self.label_dict=eval(f.read())
        f.close()

    def __getitem__(self,index):
        label = list(self.label_dict.values())[index-1]
        img_id = list(self.label_dict.keys())[index-1]
        img_path = self.file_path+str(img_id)+".jpg"
        img = np.array(Image.open(img_path))
        return img,label

    def __len__(self):
        return len(self.label_dict)
